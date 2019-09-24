class Kbcb < Formula
  desc "Afilitates developers to connect their projects to Kambria codebase"
  homepage "https://app.kambria.io"
  url "https://github.com/kambria-platform/kbcb/raw/develop/packages/mac/kbcb-0.0.1/kbcb-0.0.1.tar.gz"
  sha256 "41ef4f2c5b6c314afca4e17da8550b259179ca0b76edc4b25694e048b4af0753"

  depends_on "cmake" => :build

  def install
    rm_rf("build")
    mkdir("build")
    Dir.chdir("./build") do
      system "cmake", "..", "-DENV=\"PRODUCTION\"", "-DSHARED=\"/usr/local/Cellar/kbcb/#{version}/share/kambria-pre-push\""
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
