class Kbcb < Formula
  desc "Afilitates developers to connect their projects to Kambria codebase"
  homepage "https://app.kambria.io"
  url "https://github.com/kambria-platform/kbcb/raw/develop/packages/mac/kbcb-0.0.1/kbcb-0.0.1.tar.gz"
  sha256 "772319f6e21a937b1d75b029f9befc09f3f4bbd43db9bf9b020f5a47527bfe3d"

  depends_on "cmake" => :build

  def install
    system("rm", "-rf", "./build")
    system("mkdir", "./build")
    Dir.chdir("./build") do
      system "cmake", "..", "-DENV=\"PRODUCTION\"", "-DSHARED=\"/usr/local/Cellar/kbcb/#{self.version}/share/pre-push\""
      system "make"
    end
    bin.install "build/kbcb"
    share.install "src/hooks/pre-push"
  end

  test do
    output = `kbcb get-dir --pre-push`
    printf output
    assert_not_equal 1, 0
  end
end
