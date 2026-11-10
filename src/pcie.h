/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef PCIE_H
#define PCIE_H

#define MAX_PHYS 4

struct pcie_controller_state {
    const char *path;
    u32 controller;
    int adt_path[8];
    int adt_offset;
    
    int num_phys;
    u32 lane_mode;
    u32 link_width;
    int port_reg_cnt;
    u64 config_base;
    u64 rc_base;
    u64 axi_base;
    u64 phy_common_base;
    u64 phy_base[MAX_PHYS];
    u64 phy_ip_base[MAX_PHYS];
    u64 fuse_base;
    u32 port_count;
    u64 port_base[8];
    u64 port_ltssm_base[8];
    u64 port_phy_base[8];
    u64 port_intr2axi_base[8];
    const struct reg_info *pcie_regs;
    const struct fuse_bits *fuse_bits;

    bool initialized;
};

typedef bool(pcie_populate_regs_t)(struct pcie_controller_state*);
typedef bool(pcie_init_phys_t)(struct pcie_controller_state*);

int pcie_init(void);
int pcie_shutdown(void);

#endif
