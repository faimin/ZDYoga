# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.


Pod::Spec.new do |spec|
  spec.name = 'ZDYoga'
  spec.version = '3.0.3.1'
  spec.license =  { :type => 'MIT', :file => "LICENSE" }
  spec.homepage = 'https://yogalayout.dev/'
  spec.documentation_url = 'https://yogalayout.dev/docs'

  spec.summary = 'An embeddable and performant flexbox layout engine with bindings for multiple languages'

  spec.authors = {
    'Meta Open Source' => 'opensource@meta.com', 
    'faimin' => 'fuxianchao@gmail.com'
}
  spec.source = {
    :git => 'https://github.com/faimin/yoga.git',
    :tag => "#{spec.version.to_s}",
  }

  spec.ios.deployment_target = "10.0"

  dir_name = 'ZDYoga'

  spec.module_name = dir_name
  # spec.module_map = "#{dir_name}/module.modulemap"
  spec.requires_arc = false
  spec.pod_target_xcconfig = {
    'DEFINES_MODULE' => 'YES',
    'HEADER_SEARCH_PATHS' => '"$(PODS_TARGET_SRCROOT)"',
  }
  spec.compiler_flags = [
      '-fno-omit-frame-pointer',
      '-fexceptions',
      '-Wall',
      '-Werror',
      '-std=c++20',
      '-fPIC'
  ]
  spec.swift_version = '5.1'
  spec.source_files = "#{dir_name}/**/*.{h,cpp}"
  spec.header_mappings_dir = dir_name

  public_header_files = "#{dir_name}/*.h"
  spec.public_header_files = public_header_files

  all_header_files = "#{dir_name}/**/*.h"
  spec.private_header_files = Dir.glob(all_header_files) - Dir.glob(public_header_files)
  spec.preserve_paths = [all_header_files]
end
