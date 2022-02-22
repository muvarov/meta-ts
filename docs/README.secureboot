UEFI Secure Boot
================

UEFI Secure Boot automatically enabled if certificates file was specified during the boot.
./ci/base.yml file has env UEFI_CERT_FILE pointed to tar.gz archive which certificates.

1. Generate certificates
------------------------

Meta-ts has example script to generate certificates for UEFI:
meta-trustedsubstrate/uefi-certificates/gen_uefi_certs.sh

PK -  Primary Key (Top-level key.)
KEK - Key Exchange Keys (Keys used to sign Signatures Database and Forbidden Signatures Database updates.)
db -  Signature Database (Contains keys and/or hashes of allowed EFI binaries.).
dbx - Forbidden Signatures Database  (Contains keys and/or hashes of denylisted EFI binaries.

2. Create tar.gz archive
------------------------

tar -czf uefi_certs.tgz db.esl dbx.esl KEK.esl PK.esl

Note: several certificates can be concatenated to db.esl with cat command. I.e. cat db1.esl db2.esl > db.esl.

3. Set up an environment variable.
-------------------------------
The following kas construction can be used:
env:
  UEFI_CERT_FILE: "${TOPDIR}/...../uefi_certs.tgz"
