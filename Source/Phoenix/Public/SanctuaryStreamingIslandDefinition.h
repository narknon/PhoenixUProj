#pragma once
#include "CoreMinimal.h"
#include "SanctuaryStreamingZoneDefinition.h"
#include "SanctuaryStreamingIslandDefinition.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FSanctuaryStreamingIslandDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IslandName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSanctuaryStreamingZoneDefinition> Zones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LightingScenario;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> OctreeScenario;
    
    PHOENIX_API FSanctuaryStreamingIslandDefinition();
};

