#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "ActorProvider.generated.h"

class AActor;
class UActorSpawner;
class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UActorProvider : public UObjectProvider {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorSpawner* PreviewSpawner;
    
    UActorProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetActor(const UObject* Caller) const;
    
};

