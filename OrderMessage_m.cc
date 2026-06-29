//
// Generated file, do not edit! Created by opp_msgtool 6.3 from OrderMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "OrderMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace fooddelivery {

Register_Enum(fooddelivery::OrderType, (fooddelivery::OrderType::ORDER_REQUEST, fooddelivery::OrderType::PREP_REQUEST, fooddelivery::OrderType::FOOD_READY, fooddelivery::OrderType::DELIVERY_REQUEST, fooddelivery::OrderType::DELIVERED));

Register_Class(OrderChunk)

OrderChunk::OrderChunk() : ::inet::FieldsChunk()
{
}

OrderChunk::OrderChunk(const OrderChunk& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

OrderChunk::~OrderChunk()
{
}

OrderChunk& OrderChunk::operator=(const OrderChunk& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void OrderChunk::copy(const OrderChunk& other)
{
    this->orderId = other.orderId;
    this->orderType = other.orderType;
    this->customerAddress = other.customerAddress;
    this->orderTime = other.orderTime;
}

void OrderChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->orderId);
    doParsimPacking(b,this->orderType);
    doParsimPacking(b,this->customerAddress);
    doParsimPacking(b,this->orderTime);
}

void OrderChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->orderId);
    doParsimUnpacking(b,this->orderType);
    doParsimUnpacking(b,this->customerAddress);
    doParsimUnpacking(b,this->orderTime);
}

int OrderChunk::getOrderId() const
{
    return this->orderId;
}

void OrderChunk::setOrderId(int orderId)
{
    handleChange();
    this->orderId = orderId;
}

int OrderChunk::getOrderType() const
{
    return this->orderType;
}

void OrderChunk::setOrderType(int orderType)
{
    handleChange();
    this->orderType = orderType;
}

const char * OrderChunk::getCustomerAddress() const
{
    return this->customerAddress.c_str();
}

void OrderChunk::setCustomerAddress(const char * customerAddress)
{
    handleChange();
    this->customerAddress = customerAddress;
}

::omnetpp::simtime_t OrderChunk::getOrderTime() const
{
    return this->orderTime;
}

void OrderChunk::setOrderTime(::omnetpp::simtime_t orderTime)
{
    handleChange();
    this->orderTime = orderTime;
}

class OrderChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_orderId,
        FIELD_orderType,
        FIELD_customerAddress,
        FIELD_orderTime,
    };
  public:
    OrderChunkDescriptor();
    virtual ~OrderChunkDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(OrderChunkDescriptor)

OrderChunkDescriptor::OrderChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(fooddelivery::OrderChunk)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

OrderChunkDescriptor::~OrderChunkDescriptor()
{
    delete[] propertyNames;
}

bool OrderChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OrderChunk *>(obj)!=nullptr;
}

const char **OrderChunkDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OrderChunkDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OrderChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int OrderChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_orderId
        FD_ISEDITABLE,    // FIELD_orderType
        FD_ISEDITABLE,    // FIELD_customerAddress
        FD_ISEDITABLE,    // FIELD_orderTime
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *OrderChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "orderId",
        "orderType",
        "customerAddress",
        "orderTime",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int OrderChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "orderId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "orderType") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "customerAddress") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "orderTime") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *OrderChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_orderId
        "int",    // FIELD_orderType
        "string",    // FIELD_customerAddress
        "omnetpp::simtime_t",    // FIELD_orderTime
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **OrderChunkDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OrderChunkDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OrderChunkDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OrderChunkDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OrderChunk'", field);
    }
}

const char *OrderChunkDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OrderChunkDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        case FIELD_orderId: return long2string(pp->getOrderId());
        case FIELD_orderType: return long2string(pp->getOrderType());
        case FIELD_customerAddress: return oppstring2string(pp->getCustomerAddress());
        case FIELD_orderTime: return simtime2string(pp->getOrderTime());
        default: return "";
    }
}

void OrderChunkDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        case FIELD_orderId: pp->setOrderId(string2long(value)); break;
        case FIELD_orderType: pp->setOrderType(string2long(value)); break;
        case FIELD_customerAddress: pp->setCustomerAddress((value)); break;
        case FIELD_orderTime: pp->setOrderTime(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OrderChunk'", field);
    }
}

omnetpp::cValue OrderChunkDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        case FIELD_orderId: return pp->getOrderId();
        case FIELD_orderType: return pp->getOrderType();
        case FIELD_customerAddress: return pp->getCustomerAddress();
        case FIELD_orderTime: return pp->getOrderTime().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OrderChunk' as cValue -- field index out of range?", field);
    }
}

void OrderChunkDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        case FIELD_orderId: pp->setOrderId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_orderType: pp->setOrderType(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_customerAddress: pp->setCustomerAddress(value.stringValue()); break;
        case FIELD_orderTime: pp->setOrderTime(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OrderChunk'", field);
    }
}

const char *OrderChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr OrderChunkDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OrderChunkDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OrderChunk *pp = omnetpp::fromAnyPtr<OrderChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OrderChunk'", field);
    }
}

}  // namespace fooddelivery

namespace omnetpp {

}  // namespace omnetpp

