# IP2L

IP2L is a simple parser of the geo location provider * [Ip2Location](https://www.ip2location.com/).
This code should work fine on any Linux system.

### Prerequisites

You must first download a Ip2Location database, free version are available at :

https://lite.ip2location.com/

Take the DB1.LITE IPV4 BIN one, rename the .bin (IP2LOCATION-LITE-DB1.BIN) to ip2location.bin and
move it inside /usr/share/ip2location/ (create the directory if needed)

### Installing

Download the sources or use the git command, simply use make to build the sources


```
cd ip2l/
make
```
A binary named ip2l should be available 

```
./ip2l
use -h or --help for the usage of ip2l
```

Example of a output 

Ip as argument
```
./ip2l 8.8.8.8
[US] 8.8.8.8
```
Ip file list
```
cat /home/linux/file.txt
8.8.8.8
194.153.110.160
198.27.92.1
104.27.216.28
127.0.0.1
123.44.256.1
hello

./ip2l --file /home/linux/file.txt
[US] 8.8.8.8
[FR] 194.153.110.160
[CA] 198.27.92.1
[US] 104.27.216.28
[-] 127.0.0.1
123.44.256.1 invalid ip format
hello invalid ip format
```


## License

Ip2Location project is licensed under the MIT License

I2PL include [The Ip2Location C API](https://www.ip2location.com/development-libraries/ip2location/c/).



