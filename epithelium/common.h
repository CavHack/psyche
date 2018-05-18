/*
 * Venire Labs Inc 2018 All right reserved.
 */

#pragma once

#define TREE_SIZE 32

#define WONCE_LOG_ell1 6
#define WONCE_chksum 3 (1 << (WONCE_LOG_ell1))
#define ONCE_chksum 3
#define WONCE_ell ((WONCE_ell1) + (WONCE_chksum))
#define WONCE_w 16

/*Compile flag semaphore*/
#if 0
#define POSET_k 28
#define lamportBlock_h 5
#define HYPERGRAPH_d 10
#define HYPERGRAPH_c 14
#endif

#define POSET_tau 16
#define POSET_t (1 << (POSET_tau))

#define LAMPORTBLOCK_hhh (1 << (LAMPORTBLOCK_h))

#define HYPERGRAPH_ccc (1 << (HYPERGRAPH_c))
#define HYPERGRAPH_h ((LAMPORTBLOCK_h) * (HYPERGRAPH_d) + (HYPERGRAPH_c))

#if HYPERGRAPH_h < 64
#define HYPERGRAPH_mask ~(0xFFFFFFFFFFFFFFFFull << (HYPERGRAPH_h))
#else
#define HYPERGRAPH_mask 0xFFFFFFFFFFFFFFFFull
#endif

#define LOG_MAX_BATCH_COUNT 10
#define MAX_BATCH_COUNT (1 << (LOG_MAX_BATCH_COUNT))

#define HYPERGRAPH_OK 0
#define HYPERGRAPH_ERR_VERIF 1
#define HYPERGRAPH_ERR_ALLOC 2
#define HYPERGRAPH_ERR_BATCH 3

#define U8TO32(p)                                                              \
  (((uint32_t) ((p)[0]) << 24) | ((uint32_t) ((p)[1]) << 16) |               \
   ((uint32_t) ((p)[2]) << 8) | ((uint32_t) ((p)[3])))
