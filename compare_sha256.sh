./ft_ssl sha256 -q $@ > my.txt && shasum -a 256 $@ | sed 's/ .*//' > real.txt && diff my.txt real.txt 