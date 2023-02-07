#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicalResponseComponent.generated.h"

class UPhysicalResponseConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPhysicalResponseComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPhysicalResponseConfig*> Responses;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPhysicalResponseConfig* CurResponse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPhysicalResponseConfig*> ValidResponses;
    
public:
    UPhysicalResponseComponent();
};

