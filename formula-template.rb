class Kbcb < Formula
  desc "Afilitates developers to connect their projects to Kambria codebase"
  homepage "https://app.kambria.io"
  url "https://github.com/kambria-platform/kbcb/raw/develop/packages/mac/kbcb-0.0.1/kbcb-0.0.1.tar.gz"
  sha256 "eae084e1d9911734d7e0545a232f94d9f864cc63d2c7f4b547b376b1b165c9af"

  depends_on "cmake" => :build

  def install
    system("rm", "-rf", "./build")
    system("mkdir", "./build")
    Dir.chdir("./build") do
      system "cmake", "..", "-DENV=\"PRODUCTION\""
      system "make"
    end
    bin.install "build/kbcb"
    share.install "src/hooks/pre-push"
  end

  test do
    assert_equal 1, 1
  end
end
