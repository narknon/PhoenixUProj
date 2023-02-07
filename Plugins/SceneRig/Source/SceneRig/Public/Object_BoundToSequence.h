#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Object_BoundToSequence.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UObject_BoundToSequence : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorName;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> CachedCaller;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> CachedActor;
    
public:
    UObject_BoundToSequence();
};

