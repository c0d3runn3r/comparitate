#!/usr/bin/perl

# Goal: Create a file containing 10,000 random 4-letter strings, sorted alphabetically.
#
# Don't make the most efficient program possible, just write something natural that 
# thinks about the generic case.  The following loop (for example) uses a strlen type
# check with every iteration.  But it's easy to read and easy to change.

use Data::Dumper;
use Time::HiRes qw(time);

my $start_time=time;

# Create an array of random 4 letter strings
my $a=[];
my @letters=split(//,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");

for(my $n=0; $n<10000; $n++) {

	my $line="";
	while (length $line < 4) {
		 $line.=$letters[int rand(scalar @letters)];
	}

	push(@{$a},	$line);
}

# Sort
my @sorted= sort @{$a};


# Save
open(my $OUT, ">", "joseph_output.txt");
foreach my $line (@sorted) {

	print $OUT $line."\n";
}
close($OUT);


my $end_time=time;

print ("Elapsed time: ".int( ($end_time - $start_time) * 1000 )." ms\n");	# Small int v. round error
