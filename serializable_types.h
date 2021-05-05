#ifndef SERIALIZABLE_TYPES_H
#define SERIALIZABLE_TYPES_H

#include <QJsonArray>
#include <QMap>
#include <QPair>
#include <QString>

#include "graphics_items.h"
#include "serializers.h"


//=============================================================================
class RequestHeader : public Serializable
{
public:
    RequestHeader();
    RequestHeader(int client_id_, const QString &method_, int argument_size_);

#ifdef JSON_SERIALIZER
    bool serialize(QJsonObject& json) const override;
    bool deserialize(const QJsonObject& json) override;
#else
static_assert(false, "No serializer defined.");
#endif

    int client_id;
    QString method;
    int argument_size;
};
//=============================================================================


//=============================================================================
class InitClientArgs : public Serializable
{
public:
    InitClientArgs();
    InitClientArgs(int client_id_);

#ifdef JSON_SERIALIZER
    bool serialize(QJsonObject& json) const override;
    bool deserialize(const QJsonObject& json) override;
#else
static_assert(false, "No serializer defined.");
#endif

private:
    int client_id;
};
//=============================================================================


//=============================================================================
class AddLayerArgs : public Serializable
{
public:
    typedef QPair<int, int> Vec2i;

    AddLayerArgs();
    AddLayerArgs(const QPointF &position_, const qreal &scale_, QString layer_type_);

    ~AddLayerArgs();

    Serializable *takeLayerOwnership();

#ifdef JSON_SERIALIZER
public:
    bool serialize(QJsonObject& json) const override;
    bool deserialize(const QJsonObject& json) override;

private:
    template <typename T>
    void deserializeLayerArgs(const QJsonObject& json);
#else
static_assert(false, "No serializer defined.");
#endif

private:
    QMap<QString, void(AddLayerArgs::*)(const QJsonObject& json)> layer_deserialize {
        //{"pencil", {&AddLayerArgs::serializePencilArgs, &AddLayerArgs::deserializePencilArgs}}
        {"line",      &AddLayerArgs::deserializeLayerArgs<LineItem>},
        {"pencil",    &AddLayerArgs::deserializeLayerArgs<PencilItem>},
        {"rectangle", &AddLayerArgs::deserializeLayerArgs<RectangleItem>},
        {"ellipse",   &AddLayerArgs::deserializeLayerArgs<EllipseItem>}
    };

    Serializable *layer;

public:
    QPointF position;
    qreal scale;
    QString layer_type;
};
//=============================================================================

#endif // SERIALIZABLE_TYPES_H
