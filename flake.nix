{
  description = "Playground flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
  in
  {

    devShell.${system} = pkgs.mkShell {
      hardeningDisable = [ "all" ];
      buildInputs = with pkgs; [
        gcc-unwrapped
        gnumake
        python3
        gtest
        hyperfine
        gdb
        rr
      ];
    };
  };
}
