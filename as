#!/usr/bin/perl
use strict;
use warnings FATAL => 'all';
use Data::Dumper qw(Dumper);
use Scalar::Util qw(looks_like_number);

my %instructions = (
    NOP  => 0x00,
    PUSH => 0x03,
    POP  => 0x04,
    HLT  => 0x05,
);

open(my $in, '<', $ARGV[0]) or die "OPENING $ARGV[0]: $!\n";
open my $out, '>:raw', $ARGV[1] or die;

while (my $line = <$in>) {
    chomp $line;
    my @tokens = split / /, $line;

    foreach (@tokens) {
        print $_ . "\n";
        if (looks_like_number($_)) {
            print $out pack('i<', $_);
        } else {
            print $out pack('h', $instructions{$_});
        }
    }

    print Dumper \@tokens;
}

close $in;
close $out;