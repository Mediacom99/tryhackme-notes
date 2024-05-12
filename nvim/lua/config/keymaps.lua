local keymap = vim.keymap
local opts = { noremap = true, silent = true }
-- Directory navigation
keymap.set("n", "<leader>m", ":NvimTreeFocus<CR>", opts)
keymap.set("n", "<leader>e", ":NvimTreeToggle<CR>", opts)

-- Panels navigation
keymap.set("n", "<C-Left>", "<C-w><Left>", opts) -- Navigate Left
keymap.set("n", "<C-Down>", "<C-w><Down>", opts) -- Navigate Down
keymap.set("n", "<C-Up>", "<C-w><Up>", opts) -- Navigate Up
keymap.set("n", "<C-Right>", "<C-w><Right>", opts) -- Navigate Right

-- Window management
keymap.set("n", "<leader>sv", ":vsplit<CR>", opts) -- Split vertically
keymap.set("n", "<leader>sh", ":split<CR>", opts) -- Split horizontally
-- DOES NOT WORK keymap.set("n","<leader>sm", "MaximizerToggle<CR>", opts) -- Toggle Minimize

-- Telescope fuzzy finder
keymap.set("n", "<leader>fk", ":Telescope keymaps<CR>")
keymap.set("n", "<leader>fh", ":Telescope help_tags<CR>")
keymap.set("n", "<leader>ff", ":Telescope find_files<CR>")
keymap.set("n", "<leader>fa", ":Telescope <CR>")
keymap.set("n", "<leader>fg", ":Telescope live_grep<CR>")
keymap.set("n", "<leader>fb", ":Telescope buffers<CR>")

-- Indentation
keymap.set("v", "<", "<gv") -- Tab whatever is selected in visual mode
keymap.set("v", ">", ">gv")

-- Comments
vim.api.nvim_set_keymap("n", "<C-Bslash>", "gcc", { noremap = false }) -- CTRL + \
vim.api.nvim_set_keymap("v", "<C-Bslash>", "gcc", { noremap = false })

-- Load indent-blankline plugin
keymap.set("n", "<C-t>", ":Lazy load indent-blankline.nvim<CR>", opts)

-- Buffer bar plugin (barbar-nvim)
keymap.set("n", "<leader>c", ":BufferCloseAllButCurrent<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>1", ":BufferGoto 1<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>2", ":BufferGoto 2<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>3", ":BufferGoto 3<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>4", ":BufferGoto 4<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>5", ":BufferGoto 5<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>6", ":BufferGoto 6<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>7", ":BufferGoto 7<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>8", ":BufferGoto 8<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>9", ":BufferGoto 9<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>0", ":BufferLast<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>q", ":BufferClose<CR>", opts) --close all but current buffer
keymap.set("n", "<leader>bd", ":BufferOrderByDirectory<CR>", opts) --close all but current buffer
