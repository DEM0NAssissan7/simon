Name:           simon
Version:        1.0
Release:        1.0%{?dist}
Summary:        A program that runs any .c file

License:        MIT
URL:            https://github.com/DEM0NAssissan7/simon
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  gcc make
Requires:       gcc

%description
A program written in C that is able to compile and run any .c file, along with arguments.

%prep
%setup -q

%build
gcc -g -o out/simon src/main.c

%make_build
make

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_bindir}
cp out/%{name} $RPM_BUILD_ROOT/%{_bindir}

%clean
rm -rf $RPM_BUILD_ROOT

%files
%{_bindir}/%{name}

%license LICENSE.md

%changelog
* Mon Nov 14 2022 Abdurahman Elmawi <abdurahman.elmawi06@gmail.com>
- 1.0
- The initial release