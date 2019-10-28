Name:           kbcb
Version:        0.0.2
Release:        1%{?dist}
Summary:        Kambria Codebase CLI <kbcb>

License:        gpl2
URL:            https://app.kambria.io
Source0:        kbcb-0.0.2.tar.gz

BuildRequires:  cmake, gcc
Requires:       git, gcc


%description
kbcb afilitates developers to integrate their 
repositories to Kambria Codebase platform.


%prep
%setup -q


%build
mkdir ./build
cd ./build
cmake .. -DENV="PRODUCTION" -DSHARED="/usr/share/kbcb/kambria-pre-push" -DVER="%{version}"
make


%install
%make_install


%files
/usr/bin/kbcb
/usr/share/kbcb/kambria-pre-push
%license /usr/share/doc/kbcb/LICENSE
%doc /usr/share/doc/kbcb/README


%changelog
* Wed Oct 23 2019 Tu Phan <tphanson@kambria.io> - 0.0.2-1
- Options to disconnect Kambria Codebase
- Extra options for help and version
