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

/**
 * \file
 * \brief Interface for detected_object_set_input_habcam
 */

#ifndef KWIVER_VIAME_CORE_DETECTED_OBJECT_SET_INPUT_HABCAM_H
#define KWIVER_VIAME_CORE_DETECTED_OBJECT_SET_INPUT_HABCAM_H


#include <vital/vital_config.h>
#include <plugins/core/viame_core_export.h>

#include <vital/algo/detected_object_set_input.h>

#include <memory>

namespace viame {

class VIAME_CORE_EXPORT detected_object_set_input_habcam
  : public kwiver::vital::algorithm_impl<detected_object_set_input_habcam, kwiver::vital::algo::detected_object_set_input>
{
public:
  detected_object_set_input_habcam();
  detected_object_set_input_habcam( detected_object_set_input_habcam const& other);
  virtual ~detected_object_set_input_habcam();

  /// Return the name of this implementation
  virtual std::string impl_name() const { return "habcam"; }

  virtual void set_configuration(kwiver::vital::config_block_sptr config);
  virtual bool check_configuration(kwiver::vital::config_block_sptr config) const;

  virtual bool read_set( kwiver::vital::detected_object_set_sptr & set, std::string& image_name );

private:
  virtual void new_stream();

  class priv;
  std::unique_ptr< priv > d;
};

} // end namespace

#endif // KWIVER_VIAME_CORE_DETECTED_OBJECT_SET_INPUT_HABCAM_H
