#pragma once

#include <mem/ptr.h>
#include <threads/queue.h>

namespace emu {
    typedef void SceGxmDisplayQueueCallback(Ptr<const void> callbackData);

    struct SceGxmInitializeParams {
        uint32_t flags = 0;
        uint32_t displayQueueMaxPendingCount = 0;
        Ptr<SceGxmDisplayQueueCallback> displayQueueCallback;
        uint32_t displayQueueCallbackDataSize = 0;
        uint32_t parameterBufferSize = 0;
    };
}

struct DisplayCallback {
    Address pc;
    Address data;
    Address old_buffer;
    Address new_buffer;
};

struct GxmState {
    emu::SceGxmInitializeParams params;
    bool isInScene = false;
    Queue<DisplayCallback> display_queue;
};
