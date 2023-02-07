#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BaseObjectCopyComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBaseObjectCopyComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ExcludedComponentNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideObjectWhileAlive;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> CopiedComponents;
    
public:
    UBaseObjectCopyComponent();
    UFUNCTION(BlueprintCallable)
    void SetExistingTemplateActorHidden(bool bIsHidden);
    
};

