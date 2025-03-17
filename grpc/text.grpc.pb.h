// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: text.proto
#ifndef GRPC_text_2eproto__INCLUDED
#define GRPC_text_2eproto__INCLUDED

#include "text.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace AssetInspection {

class AssetInspectionService final {
 public:
  static constexpr char const* service_full_name() {
    return "AssetInspection.AssetInspectionService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status CheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::AssetInspection::IPResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::IPResponse>> AsyncCheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::IPResponse>>(AsyncCheckIPRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::IPResponse>> PrepareAsyncCheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::IPResponse>>(PrepareAsyncCheckIPRaw(context, request, cq));
    }
    virtual ::grpc::Status CheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::AssetInspection::TCPResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::TCPResponse>> AsyncCheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::TCPResponse>>(AsyncCheckPortRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::TCPResponse>> PrepareAsyncCheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::TCPResponse>>(PrepareAsyncCheckPortRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void CheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::IPResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void CheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::IPResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void CheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::TCPResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void CheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::TCPResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::IPResponse>* AsyncCheckIPRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::IPResponse>* PrepareAsyncCheckIPRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::TCPResponse>* AsyncCheckPortRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::AssetInspection::TCPResponse>* PrepareAsyncCheckPortRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status CheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::AssetInspection::IPResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::IPResponse>> AsyncCheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::IPResponse>>(AsyncCheckIPRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::IPResponse>> PrepareAsyncCheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::IPResponse>>(PrepareAsyncCheckIPRaw(context, request, cq));
    }
    ::grpc::Status CheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::AssetInspection::TCPResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::TCPResponse>> AsyncCheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::TCPResponse>>(AsyncCheckPortRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::TCPResponse>> PrepareAsyncCheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AssetInspection::TCPResponse>>(PrepareAsyncCheckPortRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void CheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::IPResponse* response, std::function<void(::grpc::Status)>) override;
      void CheckIP(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::IPResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void CheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::TCPResponse* response, std::function<void(::grpc::Status)>) override;
      void CheckPort(::grpc::ClientContext* context, const ::AssetInspection::Check* request, ::AssetInspection::TCPResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::AssetInspection::IPResponse>* AsyncCheckIPRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::AssetInspection::IPResponse>* PrepareAsyncCheckIPRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::AssetInspection::TCPResponse>* AsyncCheckPortRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::AssetInspection::TCPResponse>* PrepareAsyncCheckPortRaw(::grpc::ClientContext* context, const ::AssetInspection::Check& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_CheckIP_;
    const ::grpc::internal::RpcMethod rpcmethod_CheckPort_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status CheckIP(::grpc::ServerContext* context, const ::AssetInspection::Check* request, ::AssetInspection::IPResponse* response);
    virtual ::grpc::Status CheckPort(::grpc::ServerContext* context, const ::AssetInspection::Check* request, ::AssetInspection::TCPResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_CheckIP : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_CheckIP() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_CheckIP() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIP(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::IPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheckIP(::grpc::ServerContext* context, ::AssetInspection::Check* request, ::grpc::ServerAsyncResponseWriter< ::AssetInspection::IPResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_CheckPort : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_CheckPort() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_CheckPort() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckPort(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::TCPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheckPort(::grpc::ServerContext* context, ::AssetInspection::Check* request, ::grpc::ServerAsyncResponseWriter< ::AssetInspection::TCPResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_CheckIP<WithAsyncMethod_CheckPort<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_CheckIP : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_CheckIP() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::AssetInspection::Check, ::AssetInspection::IPResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::AssetInspection::Check* request, ::AssetInspection::IPResponse* response) { return this->CheckIP(context, request, response); }));}
    void SetMessageAllocatorFor_CheckIP(
        ::grpc::MessageAllocator< ::AssetInspection::Check, ::AssetInspection::IPResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::AssetInspection::Check, ::AssetInspection::IPResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_CheckIP() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIP(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::IPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CheckIP(
      ::grpc::CallbackServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::IPResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_CheckPort : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_CheckPort() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::AssetInspection::Check, ::AssetInspection::TCPResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::AssetInspection::Check* request, ::AssetInspection::TCPResponse* response) { return this->CheckPort(context, request, response); }));}
    void SetMessageAllocatorFor_CheckPort(
        ::grpc::MessageAllocator< ::AssetInspection::Check, ::AssetInspection::TCPResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::AssetInspection::Check, ::AssetInspection::TCPResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_CheckPort() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckPort(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::TCPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CheckPort(
      ::grpc::CallbackServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::TCPResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_CheckIP<WithCallbackMethod_CheckPort<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_CheckIP : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_CheckIP() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_CheckIP() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIP(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::IPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_CheckPort : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_CheckPort() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_CheckPort() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckPort(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::TCPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_CheckIP : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_CheckIP() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_CheckIP() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIP(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::IPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheckIP(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_CheckPort : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_CheckPort() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_CheckPort() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckPort(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::TCPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheckPort(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_CheckIP : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_CheckIP() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->CheckIP(context, request, response); }));
    }
    ~WithRawCallbackMethod_CheckIP() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckIP(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::IPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CheckIP(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_CheckPort : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_CheckPort() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->CheckPort(context, request, response); }));
    }
    ~WithRawCallbackMethod_CheckPort() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CheckPort(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::TCPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CheckPort(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_CheckIP : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_CheckIP() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::AssetInspection::Check, ::AssetInspection::IPResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::AssetInspection::Check, ::AssetInspection::IPResponse>* streamer) {
                       return this->StreamedCheckIP(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_CheckIP() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status CheckIP(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::IPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedCheckIP(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::AssetInspection::Check,::AssetInspection::IPResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_CheckPort : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_CheckPort() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::AssetInspection::Check, ::AssetInspection::TCPResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::AssetInspection::Check, ::AssetInspection::TCPResponse>* streamer) {
                       return this->StreamedCheckPort(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_CheckPort() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status CheckPort(::grpc::ServerContext* /*context*/, const ::AssetInspection::Check* /*request*/, ::AssetInspection::TCPResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedCheckPort(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::AssetInspection::Check,::AssetInspection::TCPResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_CheckIP<WithStreamedUnaryMethod_CheckPort<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_CheckIP<WithStreamedUnaryMethod_CheckPort<Service > > StreamedService;
};

}  // namespace AssetInspection


#endif  // GRPC_text_2eproto__INCLUDED
