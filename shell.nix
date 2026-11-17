{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    pkg-config
    opencv
    cmake
    clang-tools # Optional: provides clangd for better VS Code C++ support
  ];
}
