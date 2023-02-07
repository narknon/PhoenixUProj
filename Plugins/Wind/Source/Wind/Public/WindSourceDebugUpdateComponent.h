#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WindSourceDebugUpdateComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindSourceDebugUpdateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UpdatesPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyTickAfterBeginPlay;
    
    UWindSourceDebugUpdateComponent();
};

