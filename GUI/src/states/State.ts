import Portion from './Portion';
import MakingPortion from './MakingPortion';

export interface State {
    usablePortions: Portion[];
    discardedPortions: Portion[];
    makingPortions: MakingPortion[];
}
