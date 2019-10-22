Name:           kbcb
Version:        0.0.2
Release:        1%{?dist}
Summary:        Kambria Codebase CLI <kbcb>

License:        gpl2
URL:            https://app.kambria.io
Source0:        https://github.com/kambria-platform/kbcb

BuildRequires:  cmake, gcc, g++
Requires:       git, gcc, g++

%description
kbcb afilitates developers to integrate their 
repositories to Kambria Codebase platform.


%prep
%autosetup


%build
%configure
%make_build


%install
rm -rf $RPM_BUILD_ROOT
%make_install


%files
%license add-license-file-here
%doc add-docs-here



%changelog
* Tue Oct 22 2019 Tu Phan
- 
