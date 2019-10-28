class Kbcb < Formula
  desc "Afilitates developers to connect their repositories to Kambria Codebase platform"
  homepage "https://app.kambria.io"
  url "https://github.com/kambria-platform/kbcb/raw/master/packages/mac/kbcb-0.0.2/kbcb-0.0.2.tar.gz"
  sha256 "e8f65a89a5266ab3fc01a46fb0b7c7e7941496d7ec0c4b39dceaba0583ec7af5"

  depends_on "cmake" => :build

  def install
    rm_rf("build")
    mkdir("build")
    Dir.chdir("./build") do
      system "cmake", "..",
        "-DENV=\"production\"",
        "-DSHARED=\"/usr/local/Cellar/kbcb/#{version}/share/kambria-pre-push\"",
        "-DVER=\"#{version}\""
      system "make"
    end
    bin.install "build/kbcb"
    share.install "src/hooks/kambria-pre-push"
  end

  test do
    help = `kbcb --help`
    assert_not_equal nil, help
    shared_data = `kbcb get-dir --pre-push`
    assert_equal shared_data, "/usr/local/Cellar/kbcb/#{version}/share/kambria-pre-push\n"
  end
end
