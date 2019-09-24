class Kbcb < Formula
  desc "Afilitates developers to connect their projects to Kambria codebase"
  homepage "https://app.kambria.io"
  url "https://github.com/kambria-platform/kbcb/raw/master/packages/mac/kbcb-0.0.1/kbcb-0.0.1.tar.gz"
  sha256 "36ef2417d138329001b0b9e03f01f806b188c0e44361efc8dd937503ff771913"

  depends_on "cmake" => :build

  def install
    rm_rf("build")
    mkdir("build")
    Dir.chdir("./build") do
      system "cmake", "..",
        "-DENV=\"PRODUCTION\"",
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
