#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Components/ActorComponent.h"
#include "MissionSpawnComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMissionSpawnComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo m_missionID;
    
    UMissionSpawnComponent();
};

