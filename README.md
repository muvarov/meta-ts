Introduction
------------
This repository contains the Linaro Trustedsubstrate layers for OpenEmbedded.

* meta-trustedsubstrate

  This layer contains general recipes for secure boot and arm boards support.

Other Directories
-----------------

* ci

  This directory contains gitlab continuous integration configuration files (KAS yaml files) as well as scripts needed for this

* scripts

  This directory contains scripts used in running the CI tests

Contributing
------------
Currently, we only accept patches from the meta-arm mailing list.  For general
information on how to submit a patch, please read
https://www.openembedded.org/wiki/How_to_submit_a_patch_to_OpenEmbedded

E-mail team-ledge@linaro.org with patches created using this process. You can configure git-send-email to automatically use this address for the meta-arm repository with the following git command:

$ git config --local --add sendemail.to team-ledge@linaro.org

Commits and patches added should follow the OpenEmbedded patch guidelines:

https://www.openembedded.org/wiki/Commit_Patch_Message_Guidelines

The component being changed in the shortlog should be prefixed with the layer name (without the meta- prefix), for example:

  arm-tustedsubstrate/trusted-firmware-a: decrease frobbing level

Build
-----
1. pip install kas

2. Build one of supported targets:
	- kas build ci/qemuarm64-secureboot.yml
	- kas build ci/synquacer.yml
	- kas build ci/stm32mp157c-dk2.yaml
	- kas build ci/rockpi4b.yml

Reporting bugs
--------------
E-mail team-ledge@linaro.org with the error encountered and the steps
to reproduce the issue.

Maintainer(s)
-------------
* Maxim Uvarov <maxim.uvarov@linaro.org>
