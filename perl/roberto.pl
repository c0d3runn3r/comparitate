use Time::HiRes qw(time);

my $start = time;

my @letters = split(//, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ');
my @ar = ();

for(my $i = 0; $i < 10000; $i++) {
	my $size = scalar(@letters);
	push @ar, @letters[int(rand($size))] . @letters[int(rand($size))] . @letters[int(rand($size))] . @letters[int(rand($size))];
}

@ar = sort @ar;

my $output = '';

for(my $i = 0; $i < scalar(@ar); $i++) {
	$output .= "@ar[$i]\n";
}

open(my $fh, '>', 'roberto_output.txt');
print $fh $output;
close $fh;

print "Elapsed time: ", (time - $start) * 1000 ,"ms\n";
