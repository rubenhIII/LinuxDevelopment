#!/bin/bash

max_tries=3 ; try_counter=0; passwd=" "
while [[ $try_counter -lt $max_tries ]]; do
	try_counter=$(( $try_counter + 1 ))
	echo -n "Enter the password: "
	read passwd
	if [[ $passwd == "secret" ]]; then
		echo "Access Granted!"
		exit 0
	fi
	echo "Wrong password. You have $(( $max_tries - $try_counter)) more chances"
done

echo "You failed all chances. This will be reported!"
exit -1
