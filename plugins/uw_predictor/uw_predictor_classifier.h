/*ckwg +29
 * Copyright 2016 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef VIAME_UW_PREDICTOR_CLASSIFIER_H
#define VIAME_UW_PREDICTOR_CLASSIFIER_H

#include <plugins/uw_predictor/viame_uw_predictor_export.h>

#include <vital/algo/detection_refiner.h>

namespace viame {

class VIAME_UW_PREDICTOR_EXPORT uw_predictor_classifier :
  public kwiver::vital::algorithm_impl<
    uw_predictor_classifier, kwiver::vital::algo::detection_refiner >
{
public:
  uw_predictor_classifier();
  uw_predictor_classifier( const uw_predictor_classifier& other );
  virtual ~uw_predictor_classifier();

  // Set the name of this detector which will appear in any pipeline files
  virtual std::string impl_name() const { return "uw_predictor_classifier"; }

  // Get the current configuration (parameters) for this detector
  virtual kwiver::vital::config_block_sptr get_configuration() const;

  // Set configurations automatically parsed from input pipeline and config files
  virtual void set_configuration( kwiver::vital::config_block_sptr config );
  virtual bool check_configuration( kwiver::vital::config_block_sptr config ) const;

  // Main detection method
  virtual kwiver::vital::detected_object_set_sptr refine(
    kwiver::vital::image_container_sptr image_data,
    kwiver::vital::detected_object_set_sptr input_dets ) const;

private:
  class priv;
  const std::unique_ptr< priv > d;
};

} // end namespace

#endif /* VIAME_UW_PREDICTOR_CLASSIFIER_H */
