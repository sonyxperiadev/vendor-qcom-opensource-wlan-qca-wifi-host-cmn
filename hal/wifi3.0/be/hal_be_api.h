/*
 * Copyright (c) 2016-2021 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _HAL_BE_API_H_
#define _HAL_BE_API_H_

#include "hal_hw_headers.h"
#include "hal_rx.h"

#define HAL_RX_MSDU_EXT_DESC_INFO_GET(msdu_details_ptr) \
	((struct rx_msdu_ext_desc_info *) \
	_OFFSET_TO_BYTE_PTR(msdu_details_ptr, \
RX_MSDU_DETAILS_RX_MSDU_EXT_DESC_INFO_DETAILS_RESERVED_0A_OFFSET))

/**
 * hal_reo_setup_generic_be - Initialize HW REO block
 *
 * @hal_soc: Opaque HAL SOC handle
 * @reo_params: parameters needed by HAL for REO config
 */
void hal_reo_setup_generic_be(struct hal_soc *soc,
			      void *reoparams);

void hal_tx_desc_set_search_index_generic_be(void *desc, uint32_t search_index);

/**
 * hal_tx_desc_set_cache_set_num_generic_be - Set the cache-set-num value
 * @desc: Handle to Tx Descriptor
 * @cache_num: Cache set number that should be used to cache the index
 *                based search results, for address and flow search.
 *                This value should be equal to LSB four bits of the hash value
 *                of match data, in case of search index points to an entry
 *                which may be used in content based search also. The value can
 *                be anything when the entry pointed by search index will not be
 *                used for content based search.
 *
 * Return: void
 */
void hal_tx_desc_set_cache_set_num_generic_be(void *desc,
					      uint8_t cache_num);

/**
 * hal_rx_msdu_ext_desc_info_get_ptr_be() - Get the msdu extension
 *			descriptor pointer.
 * @msdu_details_ptr: msdu details
 *
 * Return: msdu exntension descriptor pointer.
 */
void *hal_rx_msdu_ext_desc_info_get_ptr_be(void *msdu_details_ptr);

/**
 * hal_set_link_desc_addr_be - Setup link descriptor in a buffer_addr_info
 * HW structure
 *
 * @desc: Descriptor entry (from WBM_IDLE_LINK ring)
 * @cookie: SW cookie for the buffer/descriptor
 * @link_desc_paddr: Physical address of link descriptor entry
 *
 */
void hal_set_link_desc_addr_be(void *desc, uint32_t cookie,
			       qdf_dma_addr_t link_desc_paddr);

/**
 * hal_hw_txrx_default_ops_attach_be(): Add default ops for BE chips
 * @ hal_soc_hdl: hal_soc handle
 *
 * Return: None
 */
void hal_hw_txrx_default_ops_attach_be(struct hal_soc *soc);

uint32_t hal_tx_comp_get_buffer_source_generic_be(void *hal_desc);
uint8_t hal_rx_ret_buf_manager_get_be(hal_ring_desc_t ring_desc);
void hal_rx_wbm_err_info_get_generic_be(void *wbm_desc, void *wbm_er_info1);

/**
 * hal_reo_qdesc_setup - Setup HW REO queue descriptor
 *
 * @hal_soc: Opaque HAL SOC handle
 * @ba_window_size: BlockAck window size
 * @start_seq: Starting sequence number
 * @hw_qdesc_vaddr: Virtual address of REO queue descriptor memory
 * @hw_qdesc_paddr: Physical address of REO queue descriptor memory
 * @pn_type: PN type (one of the types defined in 'enum hal_pn_type')
 *
 */
void hal_reo_qdesc_setup_be(hal_soc_handle_t hal_soc_hdl,
			    int tid, uint32_t ba_window_size,
			    uint32_t start_seq, void *hw_qdesc_vaddr,
			    qdf_dma_addr_t hw_qdesc_paddr,
			    int pn_type);

#endif /* _HAL_BE_API_H_ */