/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef PCIE_H
#define PCIE_H

typedef bool(pcie_init_controller_variant_t)();

int pcie_init(void);
int pcie_shutdown(void);

#endif
