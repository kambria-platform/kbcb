class Kbcb < Formula
  desc "Afilitates developers to connect their projects to Kambria codebase"
  homepage "https://app.kambria.io"
  url "https://github.com/kambria-platform/kbcb/raw/develop/packages/mac/kbcb-0.0.1/kbcb-0.0.1.tar.gz"
  sha256 "c9f59092bb7bb120a5b9245216b7fce01067964c1d808c035c27907376e7871d"

  depends_on "cmake" => :build

  def install
    rm_rf("build")
    mkdir("build")
    Dir.chdir("./build") do
      system "cmake", "..", "-DENV=\"PRODUCTION\"", "-DSHARED=\"/usr/local/Cellar/kbcb/#{version}/share/pre-push\""
      system "make"
    end
    bin.install "build/kbcb"
    share.install "src/hooks/pre-push"
  end

  test do
    help = `kbcb --help`
    assert_not_equal nil, help
    shared_data = `kbcb get-dir --pre-push`
    assert_equal shared_data, "/usr/local/Cellar/kbcb/#{version}/share/pre-push\n"
  end
end
