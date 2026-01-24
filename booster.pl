#!/usr/bin/perl -w

use strict;
use File::Path qw(make_path);
use File::Basename;
use Getopt::Long;

if (@ARGV == 0) {
    exit 0;
}

my @files;

for my $path (@ARGV) {
    if (-f $path) {
        push @files, $path;
    } elsif (-d $path) {
        find_files($path, \@files);
    } else {
        warn "Skipping '$path': not a file or directory\n";
    }
}

make_path("boostified/include/boost/tproc");

for my $file (@files) {
    process_file($file);
}

sub find_files {
    my ($dir, $list) = @_;
    opendir(my $dh, $dir) or die "Cannot open directory $dir: $!\n";
    while (my $entry = readdir($dh)) {
        next if $entry eq '.' || $entry eq '..';
        my $full = "$dir/$entry";
        if (-d $full) {
            find_files($full, $list);
        } elsif (-f $full && $full =~ /\.(cpp|inl|hpp|h|cc|hh|cxx|hxx)$/i) {
            push @$list, [ $entry, $full, dirname($full) ];
        }
    }
    closedir($dh);
}

sub process_file {
    my $info = shift;
    my ($name, $fullpath, $srcdir) = @$info;

    open(my $fh, '<', $fullpath) or die "Cannot read $fullpath: $!\n";
    my $content = do { local $/; <$fh> };
    close($fh);

    my $original = $content;

    $content =~ s/\bocl::/boost::/g;
    $content =~ s/\bocl\//boost\//g;
    $content =~ s/\bOCL_/BOOST_/g;

    if ($content ne $original) {
        my $reldir = substr($srcdir, length($ARGV[0]) + 1);
        my $outdir = "boostified/include/boost/$reldir";
        make_path($outdir) unless -d $outdir;

        open(my $out, '>', "$outdir/$name") or die "Cannot write $outdir/$name: $!\n";
        print $out $content;
        close($out);
    }
}
