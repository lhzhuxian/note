## https vs http

Symmetric enc/dec

Asymetric enc/dec (sign/verify)



## Java KeyStore and TrustStore

## 1. Overview

In this quick article, we'll provide an overview of the differences between a Java keystore and a Java truststore.

## 2. Concepts

In most cases, **we use a keystore and a truststore when our application needs to communicate over SSL/TLS**.

Usually, these are password-protected files that sit on the same file system as our running application. The default format used for these files is **JKS until Java 8**.

Since Java 9, though, **the default keystore format is PKCS12**. The biggest difference between JKS and PKCS12 is that JKS is a format specific to Java, while PKCS12 is a standardized and language-neutral way of storing encrypted private keys and certificates.





https://dzone.com/articles/ssl-in-java