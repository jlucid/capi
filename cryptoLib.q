\d .crypto

.crypto.md5:`:./cryptoLib 2:(`md5;1)    // md5 is a reserved function name
sha256:`:./cryptoLib 2:(`sha256;1)
sha512:`:./cryptoLib 2:(`sha512;1)

\d .

show each ((::);.crypto.md5;md5)@\:"Welcome to cryptoLib";
