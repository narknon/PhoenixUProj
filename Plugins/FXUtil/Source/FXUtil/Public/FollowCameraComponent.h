#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EFollowCameraType.h"
#include "FollowCameraComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UFollowCameraComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFollowCameraType FollowType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZValue;
    
    UFollowCameraComponent();
};

