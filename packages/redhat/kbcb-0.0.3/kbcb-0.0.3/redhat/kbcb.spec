Name:           kbcb
Version:        0.0.3
Release:        1%{?dist}
Summary:        Kambria Codebase CLI <kbcb>

License:        gpl2
URL:            https://app.kambria.io
Source0:        kbcb-0.0.3.tar.gz

BuildRequires:  cmake, gcc
Requires:       git, gcc


%description
kbcb afilitates developers to integrate their 
repositories to Kambria Codebase platform.


%global debug_package %{nil}


%prep
%setup -q


%build
mkdir ./build
cd ./build
cmake .. -DENV=production -DSHARED=/usr/local/share/kbcb/kambria-pre-push -DVER=%{version}
make


%install
cd ./build
%make_install
mkdir -p $RPM_BUILD_ROOT/usr/local/share/doc/kbcb
cd ../redhat
cp -r docs README LICENSE $RPM_BUILD_ROOT/usr/local/share/doc/kbcb


%files
/usr/local/bin/kbcb
/usr/local/share/kbcb/kambria-pre-push
%license /usr/local/share/doc/kbcb/LICENSE
%doc /usr/local/share/doc/kbcb/README
%doc /usr/local/share/doc/kbcb/docs


%changelog
* Mon Oct 28 2019 Tu Phan <tphanson@kambria.io> - 0.0.3-1
- Prune help text
- Migrate C to C++
- CMake: install/uninstall target, linking libraries
- Restructure source tree
- Use make install instead of install spec file
