---@diagnostic disable: lowercase-global

-- These numbers are lua error codes (so use specific language error codes and ignore them)
ignore = {
  "111", --setting non-standard global variable
  "212/_.*", --unused argument for vars with "_" prefix
  "121", --setting read-only global variable vim
  "122", -- setting read-only field of global variable vim
}

-- Global objects defined by the C code
read_globals = {
  "vim",
}
