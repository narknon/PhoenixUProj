#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AlignToVelocity.h"
#include "SpringFollowComponentSettings.h"
#include "SpringFollowComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USpringFollowComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpringFollowComponentSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlignToVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlignToVelocity AlignToVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpringActive;
    
    USpringFollowComponent();
    UFUNCTION(BlueprintCallable)
    void ResetPhysics();
    
    UFUNCTION(BlueprintCallable)
    void RemoveChildOffset();
    
};

