import pkgs = fmt/
import tests = fmt-tests/

./: $pkgs
./: $tests: install = false
