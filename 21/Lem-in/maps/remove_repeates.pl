#!/usr/bin/env perl

use 5.018;

$^I = ".copy";

my %links;

while (<>) {
	if (/(\w+)\-(\w+)/) {
		if ($1 eq $2) {
			next;
		}
		if (defined $links{$1}) {
			if ($2 ~~ @{$links{$1}} or $1 ~~ @{$links{$2}}) {
				next;
			} else {
				push @{$links{$1}}, $2;
				push @{$links{$2}}, $1;
				print;
			}
		} else {
			$links{$1} = [$2];
			$links{$2} = [$1];
			print;
		}
	} else {
		print;
	}
}
