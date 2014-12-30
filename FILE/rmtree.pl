#!/usr/bin/perl

use File::Path;

printf("call module of perl [rmtree]\n");

if(@ARGV == 1){
	$path = $ARGV[0];
	$ret  = rmtree($path, );

	printf("delete %d files successed \n", $ret);

}else{
	printf("argument not num \n");
}
