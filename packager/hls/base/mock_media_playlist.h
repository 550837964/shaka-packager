// Copyright 2016 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef PACKAGER_HLS_BASE_MOCK_MEDIA_PLAYLIST_H_
#define PACKAGER_HLS_BASE_MOCK_MEDIA_PLAYLIST_H_

#include <gmock/gmock.h>

#include "packager/hls/base/media_playlist.h"

namespace shaka {
namespace hls {

class MockMediaPlaylist : public MediaPlaylist {
 public:
  // The actual parameters to MediaPlaylist() (parent) constructor doesn't
  // matter because the return value can be mocked.
  MockMediaPlaylist(HlsPlaylistType type,
                    const std::string& file_name,
                    const std::string& name,
                    const std::string& group_id);
  ~MockMediaPlaylist() override;

  MOCK_METHOD1(SetMediaInfo, bool(const MediaInfo& media_info));
  MOCK_METHOD5(AddSegment,
               void(const std::string& file_name,
                    uint64_t start_time,
                    uint64_t duration,
                    uint64_t start_byte_offset,
                    uint64_t size));
  MOCK_METHOD3(AddKeyFrame,
               void(uint64_t timestamp,
                    uint64_t start_byte_offset,
                    uint64_t size));
  MOCK_METHOD6(AddEncryptionInfo,
               void(EncryptionMethod method,
                    const std::string& url,
                    const std::string& key_id,
                    const std::string& iv,
                    const std::string& key_format,
                    const std::string& key_format_versions));
  MOCK_METHOD0(AddPlacementOpportunity, void());
  MOCK_METHOD1(WriteToFile, bool(const std::string& file_path));
  MOCK_CONST_METHOD0(Bitrate, uint64_t());
  MOCK_CONST_METHOD0(GetLongestSegmentDuration, double());
  MOCK_METHOD1(SetTargetDuration, void(uint32_t target_duration));
  MOCK_CONST_METHOD0(GetNumChannels, int());
  MOCK_CONST_METHOD2(GetDisplayResolution,
                     bool(uint32_t* width, uint32_t* height));
};

}  // namespace hls
}  // namespace shaka

#endif  // PACKAGER_HLS_BASE_MOCK_MEDIA_PLAYLIST_H_
