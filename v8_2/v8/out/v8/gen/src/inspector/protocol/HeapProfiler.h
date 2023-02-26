// This file is generated by TypeBuilder_h.template.

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef v8_inspector_protocol_HeapProfiler_h
#define v8_inspector_protocol_HeapProfiler_h

#include "src/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "src/inspector/protocol/Runtime.h"

namespace v8_inspector {
namespace protocol {
namespace HeapProfiler {
using HeapSnapshotObjectId = String;
class SamplingHeapProfileNode;
class SamplingHeapProfileSample;
class SamplingHeapProfile;

// ------------- Forward and enum declarations.

// ------------- Type and builder declarations.

class  SamplingHeapProfileNode : public ::v8_crdtp::ProtocolObject<SamplingHeapProfileNode> {
public:
    ~SamplingHeapProfileNode() override { }

    protocol::Runtime::CallFrame* getCallFrame() { return m_callFrame.get(); }
    void setCallFrame(std::unique_ptr<protocol::Runtime::CallFrame> value) { m_callFrame = std::move(value); }

    double getSelfSize() { return m_selfSize; }
    void setSelfSize(double value) { m_selfSize = value; }

    int getId() { return m_id; }
    void setId(int value) { m_id = value; }

    protocol::Array<protocol::HeapProfiler::SamplingHeapProfileNode>* getChildren() { return m_children.get(); }
    void setChildren(std::unique_ptr<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileNode>> value) { m_children = std::move(value); }

    template<int STATE>
    class SamplingHeapProfileNodeBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            CallFrameSet = 1 << 1,
            SelfSizeSet = 1 << 2,
            IdSet = 1 << 3,
            ChildrenSet = 1 << 4,
            AllFieldsSet = (CallFrameSet | SelfSizeSet | IdSet | ChildrenSet | 0)};


        SamplingHeapProfileNodeBuilder<STATE | CallFrameSet>& setCallFrame(std::unique_ptr<protocol::Runtime::CallFrame> value)
        {
            static_assert(!(STATE & CallFrameSet), "property callFrame should not be set yet");
            m_result->setCallFrame(std::move(value));
            return castState<CallFrameSet>();
        }

        SamplingHeapProfileNodeBuilder<STATE | SelfSizeSet>& setSelfSize(double value)
        {
            static_assert(!(STATE & SelfSizeSet), "property selfSize should not be set yet");
            m_result->setSelfSize(value);
            return castState<SelfSizeSet>();
        }

        SamplingHeapProfileNodeBuilder<STATE | IdSet>& setId(int value)
        {
            static_assert(!(STATE & IdSet), "property id should not be set yet");
            m_result->setId(value);
            return castState<IdSet>();
        }

        SamplingHeapProfileNodeBuilder<STATE | ChildrenSet>& setChildren(std::unique_ptr<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileNode>> value)
        {
            static_assert(!(STATE & ChildrenSet), "property children should not be set yet");
            m_result->setChildren(std::move(value));
            return castState<ChildrenSet>();
        }

        std::unique_ptr<SamplingHeapProfileNode> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class SamplingHeapProfileNode;
        SamplingHeapProfileNodeBuilder() : m_result(new SamplingHeapProfileNode()) { }

        template<int STEP> SamplingHeapProfileNodeBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<SamplingHeapProfileNodeBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfileNode> m_result;
    };

    static SamplingHeapProfileNodeBuilder<0> create()
    {
        return SamplingHeapProfileNodeBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    SamplingHeapProfileNode()
    {
          m_selfSize = 0;
          m_id = 0;
    }

    std::unique_ptr<protocol::Runtime::CallFrame> m_callFrame;
    double m_selfSize;
    int m_id;
    std::unique_ptr<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileNode>> m_children;
};


class  SamplingHeapProfileSample : public ::v8_crdtp::ProtocolObject<SamplingHeapProfileSample> {
public:
    ~SamplingHeapProfileSample() override { }

    double getSize() { return m_size; }
    void setSize(double value) { m_size = value; }

    int getNodeId() { return m_nodeId; }
    void setNodeId(int value) { m_nodeId = value; }

    double getOrdinal() { return m_ordinal; }
    void setOrdinal(double value) { m_ordinal = value; }

    template<int STATE>
    class SamplingHeapProfileSampleBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            SizeSet = 1 << 1,
            NodeIdSet = 1 << 2,
            OrdinalSet = 1 << 3,
            AllFieldsSet = (SizeSet | NodeIdSet | OrdinalSet | 0)};


        SamplingHeapProfileSampleBuilder<STATE | SizeSet>& setSize(double value)
        {
            static_assert(!(STATE & SizeSet), "property size should not be set yet");
            m_result->setSize(value);
            return castState<SizeSet>();
        }

        SamplingHeapProfileSampleBuilder<STATE | NodeIdSet>& setNodeId(int value)
        {
            static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
            m_result->setNodeId(value);
            return castState<NodeIdSet>();
        }

        SamplingHeapProfileSampleBuilder<STATE | OrdinalSet>& setOrdinal(double value)
        {
            static_assert(!(STATE & OrdinalSet), "property ordinal should not be set yet");
            m_result->setOrdinal(value);
            return castState<OrdinalSet>();
        }

        std::unique_ptr<SamplingHeapProfileSample> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class SamplingHeapProfileSample;
        SamplingHeapProfileSampleBuilder() : m_result(new SamplingHeapProfileSample()) { }

        template<int STEP> SamplingHeapProfileSampleBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<SamplingHeapProfileSampleBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfileSample> m_result;
    };

    static SamplingHeapProfileSampleBuilder<0> create()
    {
        return SamplingHeapProfileSampleBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    SamplingHeapProfileSample()
    {
          m_size = 0;
          m_nodeId = 0;
          m_ordinal = 0;
    }

    double m_size;
    int m_nodeId;
    double m_ordinal;
};


class  SamplingHeapProfile : public ::v8_crdtp::ProtocolObject<SamplingHeapProfile> {
public:
    ~SamplingHeapProfile() override { }

    protocol::HeapProfiler::SamplingHeapProfileNode* getHead() { return m_head.get(); }
    void setHead(std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfileNode> value) { m_head = std::move(value); }

    protocol::Array<protocol::HeapProfiler::SamplingHeapProfileSample>* getSamples() { return m_samples.get(); }
    void setSamples(std::unique_ptr<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileSample>> value) { m_samples = std::move(value); }

    template<int STATE>
    class SamplingHeapProfileBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            HeadSet = 1 << 1,
            SamplesSet = 1 << 2,
            AllFieldsSet = (HeadSet | SamplesSet | 0)};


        SamplingHeapProfileBuilder<STATE | HeadSet>& setHead(std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfileNode> value)
        {
            static_assert(!(STATE & HeadSet), "property head should not be set yet");
            m_result->setHead(std::move(value));
            return castState<HeadSet>();
        }

        SamplingHeapProfileBuilder<STATE | SamplesSet>& setSamples(std::unique_ptr<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileSample>> value)
        {
            static_assert(!(STATE & SamplesSet), "property samples should not be set yet");
            m_result->setSamples(std::move(value));
            return castState<SamplesSet>();
        }

        std::unique_ptr<SamplingHeapProfile> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class SamplingHeapProfile;
        SamplingHeapProfileBuilder() : m_result(new SamplingHeapProfile()) { }

        template<int STEP> SamplingHeapProfileBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<SamplingHeapProfileBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfile> m_result;
    };

    static SamplingHeapProfileBuilder<0> create()
    {
        return SamplingHeapProfileBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    SamplingHeapProfile()
    {
    }

    std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfileNode> m_head;
    std::unique_ptr<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileSample>> m_samples;
};


// ------------- Backend interface.

class  Backend {
public:
    virtual ~Backend() { }

    virtual DispatchResponse addInspectedHeapObject(const String& in_heapObjectId) = 0;
    class  CollectGarbageCallback {
    public:
        virtual void sendSuccess() = 0;
        virtual void sendFailure(const DispatchResponse&) = 0;
        virtual void fallThrough() = 0;
        virtual ~CollectGarbageCallback() { }
    };
    virtual void collectGarbage(std::unique_ptr<CollectGarbageCallback> callback) = 0;
    virtual DispatchResponse disable() = 0;
    virtual DispatchResponse enable() = 0;
    virtual DispatchResponse getHeapObjectId(const String& in_objectId, String* out_heapSnapshotObjectId) = 0;
    virtual DispatchResponse getObjectByHeapObjectId(const String& in_objectId, Maybe<String> in_objectGroup, std::unique_ptr<protocol::Runtime::RemoteObject>* out_result) = 0;
    virtual DispatchResponse getSamplingProfile(std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfile>* out_profile) = 0;
    virtual DispatchResponse startSampling(Maybe<double> in_samplingInterval) = 0;
    virtual DispatchResponse startTrackingHeapObjects(Maybe<bool> in_trackAllocations) = 0;
    virtual DispatchResponse stopSampling(std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfile>* out_profile) = 0;
    virtual DispatchResponse stopTrackingHeapObjects(Maybe<bool> in_reportProgress, Maybe<bool> in_treatGlobalObjectsAsRoots) = 0;
    virtual DispatchResponse takeHeapSnapshot(Maybe<bool> in_reportProgress, Maybe<bool> in_treatGlobalObjectsAsRoots) = 0;

};

// ------------- Frontend interface.

class  Frontend {
public:
  explicit Frontend(FrontendChannel* frontend_channel) : frontend_channel_(frontend_channel) {}
    void addHeapSnapshotChunk(const String& chunk);
    void heapStatsUpdate(std::unique_ptr<protocol::Array<int>> statsUpdate);
    void lastSeenObjectId(int lastSeenObjectId, double timestamp);
    void reportHeapSnapshotProgress(int done, int total, Maybe<bool> finished = Maybe<bool>());
    void resetProfiles();

  void flush();
  void sendRawNotification(std::unique_ptr<Serializable>);
 private:
  FrontendChannel* frontend_channel_;
};

// ------------- Dispatcher.

class  Dispatcher {
public:
    static void wire(UberDispatcher*, Backend*);

private:
    Dispatcher() { }
};

// ------------- Metainfo.

class  Metainfo {
public:
    using BackendClass = Backend;
    using FrontendClass = Frontend;
    using DispatcherClass = Dispatcher;
    static const char domainName[];
    static const char commandPrefix[];
    static const char version[];
};

} // namespace HeapProfiler
} // namespace v8_inspector
} // namespace protocol

#endif // !defined(v8_inspector_protocol_HeapProfiler_h)
