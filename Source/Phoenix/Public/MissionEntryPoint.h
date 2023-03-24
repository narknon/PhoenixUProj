#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Engine/TriggerBox.h"
#include "BeaconableObject.h"
#include "MissionEntryPoint.generated.h"

class UCognitionStimuliSourceComponent;
class UMissionEntryPointEffectComponent;
class USceneComponent;

UCLASS(Blueprintable)
class AMissionEntryPoint : public ATriggerBox, public IBeaconableObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo m_missionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_ringRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMissionEntryPointEffectComponent* RingEffectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* CalloutLocator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BeaconableObjectID;
    
public:
    AMissionEntryPoint(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

