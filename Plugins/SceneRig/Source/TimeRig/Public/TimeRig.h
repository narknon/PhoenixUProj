#pragma once
#include "CoreMinimal.h"
#include "ETimeRigInitializingBehavior.h"
#include "ReferencedTimeRigBindings.h"
#include "TimeRigInterval.h"
#include "TimeRig.generated.h"

class UTimeRigElement;
class UTimeRigEvent;
class UTimeRig_StoryGraph;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRig : public UTimeRigInterval {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FReferencedTimeRigBindings> ReferencedTimeRigBindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TSet<UTimeRigEvent*> EventHull;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTimeRigElement*> ChildElements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRigInitializingBehavior InitializingBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RandomSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig_StoryGraph* StoryGraph;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> WarmUpTags;
    
    UTimeRig();
};

