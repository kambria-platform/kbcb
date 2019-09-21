class Kbcb < Formula
  desc "Afilitates developers to connect their projects to Kambria codebase"
  homepage "https://app.kambria.io"
  url "https://github.com/kambria-platform/kbcb/blob/master/packages/mac/kbcb-0.0.1/kbcb-0.0.1.zip"
  sha256 "951ac28e34d9f4a2e27bab4ec39bfd4cd3cdd8a20953fe2ee2f0abedf8873676"

  def install
    bin.install build/kbcb
    bin.share src/hooks/pre-push
  end
end