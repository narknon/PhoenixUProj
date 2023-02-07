#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OdcCollisionAreaUsageFlag.h"
#include "OdcCollisionChannelSet.h"
#include "OdcFlags.h"
#include "OdcFlagsDefinition.h"
#include "OdcGeometryMetrics.h"
#include "OdcLayerConfig.h"
#include "OdcSlopeAreaUsageFlag.h"
#include "OdcNavmeshConfig.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=OdysseyConfig)
class ODYSSEYRUNTIME_API UOdcNavmeshConfig : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcCollisionChannelSet CollisionChannelsAffectingNavmesh;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags DefaultAreaUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags CrouchAreaUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags DeepWaterAreaUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags ShallowWaterAreaUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultPenaltyMultiplier;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MarkupCollisionPreset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOdcCollisionAreaUsageFlag> CollisionAreaUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOdcSlopeAreaUsageFlag> SlopeAreaUsageFlags;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcLayerConfig LayerConfigs[32];
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlagsDefinition AreaUsage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlagsDefinition LinkUsage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlagsDefinition ObstacleBlockage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcGeometryMetrics GeometryMetrics;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultDrawDisttance;
    
public:
    UOdcNavmeshConfig();
};

